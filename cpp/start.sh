#!/usr/bin/env bash
# Kernel setup to allow the perf usage
sudo sh -c 'echo 0 > /proc/sys/kernel/perf_event_paranoid'
sudo sh -c 'echo 0 > /proc/sys/kernel/kptr_restrict'