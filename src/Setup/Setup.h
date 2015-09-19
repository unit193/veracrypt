/*
 Legal Notice: Some portions of the source code contained in this file were
 derived from the source code of TrueCrypt 7.1a, which is 
 Copyright (c) 2003-2012 TrueCrypt Developers Association and which is 
 governed by the TrueCrypt License 3.0, also from the source code of
 Encryption for the Masses 2.02a, which is Copyright (c) 1998-2000 Paul Le Roux
 and which is governed by the 'License Agreement for Encryption for the Masses' 
 Modifications and additions to the original source code (contained in this file) 
 and all other portions of this file are Copyright (c) 2013-2015 IDRIX
 and are governed by the Apache License 2.0 the full text of which is
 contained in the file License.txt included in VeraCrypt binary and source
 code distribution packages. */

#ifndef SETUP_H
#define SETUP_H

#ifdef __cplusplus
extern "C" {
#endif

// Specifies what files to install, where (determined by the prefix), and in what order
static char *szFiles[]=
{
	"AVeraCrypt User Guide.pdf",
	"ALicense.txt",
	"ALICENSE",
	"ANOTICE",
	"AVeraCrypt.exe",
	"AVeraCryptExpander.exe",
	"AVeraCrypt Format.exe",
	"AVeraCrypt-x86.exe",
	"AVeraCryptExpander-x86.exe",
	"AVeraCrypt Format-x86.exe",
	"AVeraCrypt-x64.exe",
	"AVeraCryptExpander-x64.exe",
	"AVeraCrypt Format-x64.exe",
	"Averacrypt.sys",
	"Averacrypt-x64.sys",
	"Dveracrypt.sys",
	"AVeraCrypt Setup.exe",
	"ALanguage.ar.xml",
	"ALanguage.be.xml",
	"ALanguage.bg.xml",
	"ALanguage.ca.xml",
	"ALanguage.cs.xml",
	"ALanguage.da.xml",
	"ALanguage.de.xml",
	"ALanguage.el.xml",
	"ALanguage.es.xml",
	"ALanguage.et.xml",
	"ALanguage.eu.xml",
	"ALanguage.fa.xml",
	"ALanguage.fi.xml",
	"ALanguage.fr.xml",
	"ALanguage.hu.xml",
	"ALanguage.id.xml",
	"ALanguage.it.xml",
	"ALanguage.ja.xml",
	"ALanguage.ka.xml",
	"ALanguage.ko.xml",
	"ALanguage.lv.xml",
	"ALanguage.my.xml",
	"ALanguage.nl.xml",
	"ALanguage.nn.xml",
	"ALanguage.pl.xml",
	"ALanguage.pt-br.xml",
	"ALanguage.ru.xml",
	"ALanguage.sk.xml",
	"ALanguage.sl.xml",
	"ALanguage.sv.xml",
	"ALanguage.tr.xml",
	"ALanguage.uk.xml",
	"ALanguage.uz.xml",
	"ALanguage.vi.xml",
	"ALanguage.zh-cn.xml",
	"ALanguage.zh-hk.xml",
	"ALanguage.zh-tw.xml"
};

// Specifies what files are included in self-extracting packages (no other files will be packaged or extracted).
static char *szCompressedFiles[]=
{
	"VeraCrypt User Guide.pdf",
	"License.txt",
	"LICENSE",
	"NOTICE",
	"VeraCrypt.exe",
	"VeraCryptExpander.exe",
	"VeraCrypt Format.exe",
	"VeraCrypt-x64.exe",
	"VeraCryptExpander-x64.exe",
	"VeraCrypt Format-x64.exe",
	"veracrypt.sys",
	"veracrypt-x64.sys",
	"Language.ar.xml",
	"Language.be.xml",
	"Language.bg.xml",
	"Language.ca.xml",
	"Language.cs.xml",
	"Language.da.xml",
	"Language.de.xml",
	"Language.el.xml",
	"Language.es.xml",
	"Language.et.xml",
	"Language.eu.xml",
	"Language.fa.xml",
	"Language.fi.xml",
	"Language.fr.xml",
	"Language.hu.xml",
	"Language.id.xml",
	"Language.it.xml",
	"Language.ja.xml",
	"Language.ka.xml",
	"Language.ko.xml",
	"Language.lv.xml",
	"Language.my.xml",
	"Language.nl.xml",
	"Language.nn.xml",
	"Language.pl.xml",
	"Language.pt-br.xml",
	"Language.ru.xml",
	"Language.sk.xml",
	"Language.sl.xml",
	"Language.sv.xml",
	"Language.tr.xml",
	"Language.uk.xml",
	"Language.uz.xml",
	"Language.vi.xml",
	"Language.zh-cn.xml",
	"Language.zh-hk.xml",
	"Language.zh-tw.xml"
};

#define FILENAME_64BIT_DRIVER	"veracrypt-x64.sys"
#define NBR_COMPRESSED_FILES (sizeof(szCompressedFiles) / sizeof(szCompressedFiles[0]))

void localcleanup (void);
BOOL StatDeleteFile ( char *lpszFile, BOOL bCheckForOldFile );
BOOL StatRemoveDirectory ( char *lpszDir );
HRESULT CreateLink ( char *lpszPathObj , char *lpszArguments , char *lpszPathLink );
void GetProgramPath ( HWND hwndDlg , char *path );
void StatusMessage (HWND hwndDlg, char *stringId);
void StatusMessageParam (HWND hwndDlg, char *stringId, char *param);
void ClearLogWindow (HWND hwndDlg);
void StatusMessage ( HWND hwndDlg , char *stringId );
void StatusMessageParam ( HWND hwndDlg , char *stringId , char *param );
void RegMessage ( HWND hwndDlg , char *txt );
void RegRemoveMessage (HWND hwndDlg, char *txt);
void CopyMessage ( HWND hwndDlg , char *txt );
void RemoveMessage ( HWND hwndDlg , char *txt );
void IconMessage ( HWND hwndDlg , char *txt );
static int CALLBACK BrowseCallbackProc ( HWND hwnd , UINT uMsg , LPARAM lp , LPARAM pData );
void LoadLicense ( HWND hwndDlg );
void DetermineUpgradeDowngradeStatus (BOOL bCloseDriverHandle, LONG *driverVersionPtr);
BOOL DoFilesInstall ( HWND hwndDlg , char *szDestDir );
BOOL DoRegInstall ( HWND hwndDlg , char *szDestDir , BOOL bInstallType );
BOOL DoRegUninstall (HWND hwndDlg, BOOL bRemoveDeprecated);
BOOL DoServiceUninstall ( HWND hwndDlg , char *lpszService );
BOOL DoDriverUnload ( HWND hwndDlg );
BOOL DoShortcutsInstall ( HWND hwndDlg , char *szDestDir , BOOL bProgGroup, BOOL bDesktopIcon );
BOOL DoShortcutsUninstall (HWND hwndDlg, char *szDestDir);
void OutcomePrompt ( HWND hwndDlg , BOOL bOK );
void DoUninstall ( void *hwndDlg );
void DoInstall ( void *hwndDlg );
void SetInstallationPath (HWND hwndDlg);
BOOL UpgradeBootLoader (HWND hwndDlg);
BOOL CALLBACK InstallDlgProc ( HWND hwndDlg , UINT msg , WPARAM wParam , LPARAM lParam );

extern BOOL bDevm;
extern BOOL Rollback;
extern BOOL bUpgrade;
extern BOOL bPossiblyFirstTimeInstall;
extern BOOL bRepairMode;
extern BOOL bReinstallMode;
extern BOOL bSystemRestore;
extern BOOL bDisableSwapFiles;
extern BOOL bForAllUsers;
extern BOOL bRegisterFileExt;
extern BOOL bAddToStartMenu;
extern BOOL bDesktopIcon;
extern BOOL bDesktopIconStatusDetermined;
extern BOOL SystemEncryptionUpdate;
extern BOOL bRestartRequired;
extern HMODULE volatile SystemRestoreDll;
extern char InstallationPath[TC_MAX_PATH];
extern char SetupFilesDir[TC_MAX_PATH];

#ifdef __cplusplus
}
#endif

#endif	// #ifndef SETUP_H
