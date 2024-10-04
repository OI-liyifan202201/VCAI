
powershell Invoke-WebRequest -Uri \"https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-user\"  -OutFile VSC.exe

VSC.exe /VERYSILENT /SP-

del VSC.exe

taskkill /f /im code.exe>nul 2>nul

echo IAKIOI > C:\VSc-cpp\install-ok.txt


for /f "tokens=2,*" %%A in ('reg query HKCU\Environment /v PATH 2^>nul') do set my_user_path=%%B

setx path "%my_user_path%;%appdata%\..\Local\Programs\Microsoft VS Code\bin"
