#!/bin/bash

NUM_TRIALS=1000
OUTPUT_FILE="tlb_results.csv"

echo "num_pages,time_per_access_us" > $OUTPUT_FILE

for ((num_pages=1; num_pages<=2048; num_pages*=2)); do
    ./tlb $num_pages $NUM_TRIALS >> $OUTPUT_FILE
done
