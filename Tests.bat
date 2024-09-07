@echo off

for %%f in (out\build\x86-debug\Tests\*.exe)   do call %%f
for %%f in (out\build\x86-release\Tests\*.exe) do call %%f
for %%f in (out\build\x64-debug\Tests\*.exe)   do call %%f
for %%f in (out\build\x64-release\Tests\*.exe) do call %%f

pause
