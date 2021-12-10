# 6233_final_project

Use ./build.sh to compile the entire repo

Part 1
./run <filename> [-r|-w] <block_size> <block_count>
will return time cost and XOR
  
Part 2
./run2 <filename> <block_size>
return block_count

Part 6
./fast <filename>
return XOR, the speed of the read
Note: block_size is hardcoded, using the best-performing block_size

./fast_noxor <filename>
The speed of the read (Does NOT return XOR)
Note: block_size is hardcoded, using the best-performing block_size
