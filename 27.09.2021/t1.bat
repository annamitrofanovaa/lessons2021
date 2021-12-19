@echo off

for /L %%A in (33,1,255) do (
    cmd /C exit %%A
    call echo %%A - %%^=ExitCodeAscii%%
)
