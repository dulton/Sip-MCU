/* Copyright (C) 2002  Andy Pennell
   22.3.2007 - minor modifications by Jaroslav Libak

   You can use code snippets and source code downloads in your applications as long as

   * You keep all copyright notices in the code intact.
   * You do not sell or republish the code or it's associated article without the author's written agreement
   * You agree the code is provided as-is without any implied or express warranty. 
*/

// SYSTEM INCLUDES
// APPLICATION INCLUDES

// For compilers that support precompilation, includes "wx.h".

#include "Stdafx.h"
#include "mdump.h"
#include "assert.h"
// DEFINES
// EXTERNAL FUNCTIONS
// EXTERNAL VARIABLES
// CONSTANTS
// STATIC VARIABLE INITIALIZATIONS
LPCTSTR MiniDumper::m_szAppName;

// MACROS
// GLOBAL VARIABLES
// GLOBAL FUNCTIONS

/* //////////////////////////// PUBLIC //////////////////////////////////// */

/* ============================ CREATORS ================================== */

MiniDumper::MiniDumper( LPCTSTR szAppName )
{
   // if this assert fires then you have two instances of MiniDumper
   // which is not allowed
   assert( m_szAppName==NULL );

   m_szAppName = szAppName ? strdup(szAppName) : "Application";

   ::SetUnhandledExceptionFilter( TopLevelFilter );
}

MiniDumper::~MiniDumper()
{
   free((void *)m_szAppName);
}

/* ============================ MANIPULATORS ============================== */

/* ============================ ACCESSORS ================================= */

/* ============================ INQUIRY =================================== */

/* //////////////////////////// PROTECTED ///////////////////////////////// */

/* //////////////////////////// PRIVATE /////////////////////////////////// */

LONG MiniDumper::TopLevelFilter( struct _EXCEPTION_POINTERS *pExceptionInfo )
{
   LONG retval = EXCEPTION_CONTINUE_SEARCH;
   HWND hParent = NULL;						// find a better value for your app

   // firstly see if dbghelp.dll is around and has the function we need
   // look next to the EXE first, as the one in System32 might be old 
   // (e.g. Windows 2000)
   HMODULE hDll = NULL;
   char szDbgHelpPath[_MAX_PATH];

   if (GetModuleFileName( NULL, szDbgHelpPath, _MAX_PATH))
   {
      char *pSlash = strchr(szDbgHelpPath, '\\');
      if (pSlash)
      {
         strcpy(pSlash + 1, "DBGHELP.DLL");
         hDll = ::LoadLibrary(szDbgHelpPath);
      }
   }

   if (hDll == NULL)
   {
      // load any version we can
      hDll = ::LoadLibrary(_T("DBGHELP.DLL"));
   }

   LPCTSTR szResult = NULL;

   if (hDll)
   {
      MINIDUMPWRITEDUMP pDump = (MINIDUMPWRITEDUMP)::GetProcAddress( hDll, "MiniDumpWriteDump");
      if (pDump)
      {
         char szDumpPath[_MAX_PATH];
         char szScratch [_MAX_PATH];

		 strcpy(szDumpPath,".\\");
         //strcat( szDumpPath, ".\\");
         strcat( szDumpPath, m_szAppName);
         strcat( szDumpPath, ".dmp");

         // ask the user if they want to save a dump file
         if (::MessageBox(NULL, _T("��������������,Dump�ļ����԰���������Ա�޸�����,\n��Ҫ�����ڴ�ת��(Dump�ļ�)��"), m_szAppName, MB_YESNO )==IDYES)
         {
            // create the file
            HANDLE hFile = ::CreateFile( szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
               FILE_ATTRIBUTE_NORMAL, NULL );

            if (hFile != INVALID_HANDLE_VALUE)
            {
               _MINIDUMP_EXCEPTION_INFORMATION ExInfo;

               ExInfo.ThreadId = ::GetCurrentThreadId();
               ExInfo.ExceptionPointers = pExceptionInfo;
               ExInfo.ClientPointers = NULL;

               // write the dump
               BOOL bOK = pDump( GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpNormal, &ExInfo, NULL, NULL );
               if (bOK)
               {
                  TPRINTF(szScratch, sizeof(szScratch), _T("Debug�ļ��ɹ����浽 '%s'\n�뽫���ļ������� b-52-1@163.com"), szDumpPath );
                  szResult = szScratch;
                  retval = EXCEPTION_EXECUTE_HANDLER;
               }
               else
               {
                  TPRINTF(szScratch, sizeof(szScratch),_T("�޷�����ת���ļ��� '%s' (������� %d)"), szDumpPath, GetLastError() );
                  szResult = szScratch;
               }
               ::CloseHandle(hFile);
            }
            else
            {
               TPRINTF( szScratch, sizeof(szScratch), _T("�޷�����ת���ļ� '%s' (������� %d)"), szDumpPath, GetLastError() );
               szResult = szScratch;
            }
         }
      }
      else
      {
         szResult = _T("DBGHELP.DLL too old");
      }
   }
   else
   {
      szResult = _T("DBGHELP.DLL not found");
   }

   if (szResult)
      ::MessageBox( NULL, szResult, m_szAppName, MB_OK );

   return retval;
}

/* ============================ FUNCTIONS ================================= */