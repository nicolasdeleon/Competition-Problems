#!/bin/bash
CPP_NAME=${1?Error: no cpp file}
OUTPUT_NAME=${2?Error: no name given}

g++ $CPP_NAME -o $OUTPUT_NAME