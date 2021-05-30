# files-encryption-decryption

## Author: Noor AlAli

### Description:
- C++ program that implements the following two cases:
• Case 1: Encrypt files with certain extension using AES-CBC-256.
• Case 2: Decrypt encrypted files.

- Input Format:
  - The program is executed using the following command format:
- $ g++ main.cpp -o exe
- $ ./exe <casenumber> <inputfile-key> <extension for case 1 ONLY>

- Example
    - $ g++ main.cpp -o exe
    -  ./exe 1 key.txt rtf

### Output Format:
1. If case 1 is selected, then all the required files will be encrypted. If file
file_name.ext is encrypted, then the new encrypted file will be named as
file_name.ext.enc. The original file will be deleted, and a summary of encrypted
file names will be printed on the terminal.
2. If case 2 is selected, then all encrypted files will be decrypted, original file names
will be restored, encrypted files will be deleted, and a summary of all file names
will be printed on the terminal.