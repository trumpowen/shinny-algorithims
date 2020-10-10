#!/usr/bin/env python3 

import sys 
import os 

def run_python(file):
    res = os.system(f"python3 {file}")
    return res 

def run_c(file) : 
    output_file = f"{file.rsplit('.c')[0]}"
    res = os.system(f"gcc -std=c99 -g {file} -o {output_file}")
    if not res:
        res = os.system(f"{output_file}")
    return res 

def run_cpp(file) : 
    output_file = f"{file.rsplit('.cpp')[0]}"
    res = os.system(f"g++ -std=c11 -g {file} -o {output_file}")
    if not res : 
        res = os.system(f"./out")
    return res 

def run_kotlin(file) :
    output_file = f"{file.rsplit('.c')[0]}.jar"
    res = os.system(f"kotlinc {file} -include-runtime -d {output_file}")
    if not res:
        res = os.system(f"java -jar {output_file}")
    return res 

def file_processor(file : str):
    print(f"Running {file} ....")
    res = None 
    if file.endswith('.py'):
        res = run_python(file)
    if file.endswith('.c'):
        res = run_c(file) 
    if file.endswith('.cpp'):
        res = run_cpp(file)
    if file.endswith('.kt'):
        res = run_kotlin(file)
    
    if not res:
        print(f"Failed to process file {file}")

    return res 

def run_all(folder) : 
    files = os.listdir(folder)
    map( file_processor, files)
    
    

def main(): 
    target = sys.argv[1]
    target  = os.path.abspath(target)
    if os.path.isdir(target):
        os.chdir(target)
        run_all(target)
    else:
        target_folder = target.rsplit('.')[0]
        target = os.path.join(target_folder, os.path.basename(target))
        
        os.chdir(target_folder)
        file_processor(target)


main() 
