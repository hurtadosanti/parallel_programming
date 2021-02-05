#!/usr/bin/env bash
# Kernel setup to allow the perf usage
sudo apt-get install -yqq valgrind linux-tools-virtual linux-tools-generic linux-tools-$(uname -r)
sudo sh -c 'echo 0 > /proc/sys/kernel/perf_event_paranoid'
sudo sh -c 'echo 0 > /proc/sys/kernel/kptr_restrict'