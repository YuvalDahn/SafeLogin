# SafeLogin

This project is a project where you enter a password,
and if it matches the password that its hash is saved in the program it will say good job,
but if it dosen't match, a photo of you from the webcam will be saved

## Compiling

In orded to compile this project, you need to have `openssl` and `opencv` installed,
You can have them installed in your c:// drive as defined in the [SafeLogin.vcxproj](SafeLogin/SafeLogin.vcxproj)

or you can edit the Project Properties using visual studio to the place you have downloaded `openssl` and `opencv` respectively.
### The places you will need to edit
* Project -> (project name) Properties -> Configuration Properties -> VC++ Directories -> Include Directories - This is the place for the include folders
* Project -> Properties -> Configuration Properties -> VC++ Directories -> Library Directories - This is the place for the lib folders
* Project -> Properties -> Configuration Properties -> Linker -> Input -> Additional Dependencies - This the place for the names of the .lib files
