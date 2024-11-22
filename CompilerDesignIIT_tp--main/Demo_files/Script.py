#This Script is for compiling all the file ..its just a replacement for the make file as I prefer bash > python > Cmake ..

import os
import subprocess
import uuid

def compile_lex_files(file_list):
    compiled_binaries = []  # To store compiled binary names
    for lex_file in file_list:
        # Generate a unique name for the lex output file
        lex_output = f"lex_{uuid.uuid4().hex}.c"

        # Compile lex file using flex and output to the unique name
        subprocess.run(["flex", "-o", lex_output, lex_file])

        # Extract the lex file's base name (without extension)
        base_name = os.path.splitext(lex_file)[0]

        # Compile the lex output using gcc and store binary name
        binary_name = f"{base_name}_lexer"
        subprocess.run(["gcc", lex_output, "-o", binary_name])
        compiled_binaries.append(binary_name)

        # Clean up the lex output file
        os.remove(lex_output)
    
    return compiled_binaries

def run_binaries_on_inputs(binaries, input_files):
    for binary_name in binaries:
        for input_file in input_files:
            if input_file.startswith("inp"):
                print(f"Running {binary_name} with {input_file}")
                subprocess.run(["./" + binary_name, input_file])

if __name__ == "__main__":
    lex_files = [file for file in os.listdir(".") if file.endswith(".l")]
    input_files = [file for file in os.listdir(".") if file.startswith("inp")]

    compiled_binaries = compile_lex_files(lex_files)
    run_binaries_on_inputs(compiled_binaries, input_files)


