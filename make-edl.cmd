::
:: -- Generate *.EDL files for all examples;
:: -- Windows version; for Linux use "make edl"
::

for /D %%G IN (demo*) do (
   pushd %%G
   if EXIST make-edl.cmd (
        call make-edl.cmd
      )
   popd
)

for /D %%G IN (main*) do (
   pushd %%G
   if EXIST make-edl.cmd (
        call make-edl.cmd
      )
   popd
)

for /D %%G IN (test*) do (
   pushd %%G
   if EXIST make-edl.cmd (
        call make-edl.cmd
      )
   popd
)

for /D %%G IN (tutorial*) do (
   pushd %%G
   if EXIST make-edl.cmd (
        call make-edl.cmd
      )
   popd
)
