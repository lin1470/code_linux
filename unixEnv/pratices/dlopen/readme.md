> 编译生成动态库的问题
```
gcc test.c -shared -fPIC -o libtest.so 
```

编译运行main.c文件
```
gcc main.c -o main -ldl
```
