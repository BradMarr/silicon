import sys
import os
import shutil

compiler = ''
output_flag = ''    # Must include space at the end if necessary

if compiler != '' and output_flag != '':
    pass
elif shutil.which("g++"):
    compiler = 'g++'
    output_flag = '-o '
elif shutil.which("clang++"):
    compiler = 'clang++'
    output_flag = '-o '
elif shutil.which("icpc"):
    compiler = 'icpc'
    output_flag = '-o '
elif shutil.which("tcc"):
    compiler = 'tcc'
    output_flag = '-o '
elif shutil.which("pgc++"):
    compiler = 'pgc++'
    output_flag = '-o '
elif shutil.which("CC"):
    compiler = 'CC'
    output_flag = '-o '
elif shutil.which("bcc32"):
    compiler = 'bcc32'
    output_flag = '-o '
elif shutil.which("cl"):
    compiler = 'cl'
    output_flag = '/Fe:'
else:
    print("C++ compiler not found, please provide compiler and output flag in `run.py`")
    exit(1)

files = os.listdir()
cpp_files = [file for file in files if file.endswith('.cpp')]
os.system(compiler + " " + output_flag + "main.out" + " " + " ".join(cpp_files))

args = sys.argv[1:]
os.system("./main.out " + " ".join(args))

os.remove("main.out")