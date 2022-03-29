#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <Python.h>
#include <wchar.h>

int main() {
	Py_Initialize();
    
    PyRun_SimpleString("import sys;import os; print(os.getcwd()); sys.path.append('/home/gaurav/Desktop/lifecycle/'); os.chdir('/home/gaurav/Desktop/lifecycle/'); print(os.getcwd()); sys.argv = ['']");

	// fp = _Py_fopen(filename1, "r");
	// PyRun_SimpleFile(fp, filename1);

    // PyRun_SimpleString("print(os.listdir())");
    int idx=0;
    PyObject *module = NULL;

    module = PyImport_ImportModule("pyRun_main");
    if (!module) {
        goto done;
    }

    PyObject *result = PyObject_CallMethod(module, "main","i",idx);
        if (!result) {
            goto done;
        }

    done:
        PyErr_Print();
        Py_CLEAR(module);
        Py_Finalize();
        return 0;
}

// make c_enf c_build  PROJECT=tool_detection
// ./example_tool_detection

//gcc main_test.c -I/home/gaurav/miniconda3/envs/tf_gpu/include/python3.6m -I/home/gaurav/miniconda3/envs/tf_gpu/include/python3.6m  -Wno-unused-result -Wsign-compare -march=nocona -mtune=haswell -ftree-vectorize -fPIC -fstack-protector-strong -fno-plt -O3 -ffunction-sections -pipe -isystem /home/gaurav/miniconda3/envs/tf_gpu/include -fdebug-prefix-map=/home/builder/ktietz/cos6/ci_cos6/python_1622833237666/work=/usr/local/src/conda/python-3.6.13 -fdebug-prefix-map=/home/gaurav/miniconda3/envs/tf_gpu=/usr/local/src/conda-prefix -fuse-linker-plugin -ffat-lto-objects -flto-partition=none -flto -DNDEBUG -fwrapv -O3 -Wall -L/home/gaurav/miniconda3/envs/tf_gpu/lib/python3.6/config-3.6m-x86_64-linux-gnu -L/home/gaurav/miniconda3/envs/tf_gpu/lib -lpython3.6m -lpthread -ldl -lutil -lm  -Xlinker -export-dynamic -fno-lto


