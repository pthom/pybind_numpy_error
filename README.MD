Two consecutive import of numpy/cv2/scipy/matplotlib inside the pybind11 interpreter
will fails.
I suspect the original error might be either inside numpy or inside pybind11.

The following code will fail : 

`````cpp
void call_python_interpreter() {
  py::scoped_interpreter guard{};
  py::exec("import numpy");
}

int main() {
  call_python_interpreter();
  std::cout << "Call 1 OK\n"; 
  call_python_interpreter();
  std::cout << "Call 2 OK\n"; 
}
`````

This was tested under various configurations :
under various configurations : 
- OSX / python 2.7.14 /  64 bits
- OSX / python 3.6.5 /  64 bits
- Linux / python 3.6.4 64 bits
- Windows / python 3.6.5 / 32 bits


See details below: 


#### pybind11 version
````
commit 307ea6b7fdc77ae6d42ac71fef74ff6924498e58 (HEAD -> master, origin/master, origin/HEAD)
Author: David Caron <dcaron05@gmail.com>
Date:   Tue Apr 24 10:16:18 2018 -0400
    Typo
````

#### OSX / python 2.7.14 /  64 bits

````
(env) ➜  build git:(master) python --version
Python 2.7.14
(env) ➜  build git:(master) pip list | grep numpy
numpy                         1.14.2
(env) ➜  build git:(master) ./test_np_pybind
Call 1 OK
[1]    27509 segmentation fault  ./test_np_pybind
````

#### OSX / python 3.6.5 /  64 bits
````
(env3) ➜  build git:(master) python --version
Python 3.6.5
(env3) ➜  build git:(master) pip list | grep n
numpy      1.14.2
(env3) ➜  build git:(master) ./test_np_pybind
Call 1 OK
[1]    27723 segmentation fault  ./test_np_pybind
````

#### Windows / python 3.6.5 / 32 bits
````
>PYTHON --version
Python 3.6.5 32 bits
````

`Exception thrown at 0x5178C526 (multiarray.cp36-win32.pyd) in test_np_pybind.exe: 0xC0000005: Access violation writing location 0x0000000A. If there is a handler for this exception, the program may be safely continued.`

#### Linux / python 3.6.4 64 bits

````
 build git:(master) ✗ python  --version
Python 3.6.4 :: Anaconda, Inc.
➜  build git:(master) ✗ pip list | grep numpy
numpy (1.14.2)
numpydoc (0.7.0)
➜  build git:(master) ✗ file test_np_pybind 
test_np_pybind: ELF 64-bit LSB executable, x86-64, version 1 (GNU/Linux), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=b33f891a7db3e33322cd6099a1f01f952bbc0bd8, not stripped
➜  build git:(master) ✗ ./test_np_pybind 
Call 1 OK
[1]    4187 segmentation fault  ./test_np_pybind
````

A strace log is provided in the file strace.txt
