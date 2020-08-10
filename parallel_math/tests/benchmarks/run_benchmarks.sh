#!/usr/bin/env bash
 /home/shurtado/.local/bin/pytest --benchmark-autosave parallel_math_benchmark_tests.py --size=512
 /home/shurtado/.local/bin/pytest --benchmark-autosave parallel_math_benchmark_tests.py --size=1024
 /home/shurtado/.local/bin/pytest --benchmark-autosave parallel_math_benchmark_tests.py --size=524228
 /home/shurtado/.local/bin/pytest --benchmark-autosave parallel_math_benchmark_tests.py --size=1048576
 /home/shurtado/.local/bin/pytest --benchmark-autosave parallel_math_benchmark_tests.py --size=536870912
 /home/shurtado/.local/bin/pytest --benchmark-autosave parallel_math_benchmark_tests.py --size=1073741824