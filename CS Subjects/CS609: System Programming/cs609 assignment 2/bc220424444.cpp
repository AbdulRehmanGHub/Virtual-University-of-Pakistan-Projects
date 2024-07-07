/*	Name: Abdul Rehman
	VU-ID: BC220424444
						*/
#include <iostream>
#include <windows.h>
#include <tchar.h>

int main(){
    STARTUPINFO si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;

//Set path to the executable program.
    _TCHAR szPath[MAX_PATH];
    _sntprintf(szPath, MAX_PATH, _T("%s\\PrintText.exe"), _T("C:\\Users\\Public\\Documents"));

//Create the child process.
    if (CreateProcess(
        szPath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        std::cout<<"Child process is successfully created. \nID: "<<pi.dwProcessId<<"\nThread ID: "<<pi.dwThreadId<<std::endl;

// Wait for child process to complete.
        WaitForSingleObject(pi.hProcess, INFINITE);

// Close process and thread handles.
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else{
        std::cerr<<"Error creating child process. Error code: "<<GetLastError() <<std::endl;
    }
    return 0;
}

