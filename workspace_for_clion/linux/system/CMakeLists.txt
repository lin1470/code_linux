cmake_minimum_required(VERSION 3.9)
project(system)

set(CMAKE_CXX_STANDARD 11)

add_executable(system main.cpp day06/process_file.cpp day06/multi_process.cpp day06/pipe.cpp day06/pipe2.cpp day06/fpath.conf.cpp day06/nmap.cpp day06/parent_child_mmap.cpp day06/anon_mmap.cpp day06/mmap_r_ipc.cpp day06/mmap_w_ipc.cpp signal/kill.cpp signal/raise.cpp signal/alarm.cpp signal/alarm_num.cpp signal/settitimer.cpp signal/signal_set.cpp signal/signal.cpp demon/setsid.cpp demon/process_work.cpp thread/pthread_create.cpp thread/loop_pthread_create.c thread/hh.c thread/pthread_exit.c thread/phtead_join.c thread/pthread_attr.c thread/pthread_uncle.c thread/pthread_uncle_mutex.c thread/rwlock.c thread/condition.c thread/people.dine.c)