@echo off
for /l %%i in (1, 1, 10000) do (
echo test #%%i >> output.txt
Trzy-drzwi-auto.exe < input.txt | findstr /N /c:"without switching" >> output.txt
)
echo.
pause

