## How to: build
```bash
cd ${path-to-src}
cmake -S . -B _build # _build here is folder to build
cmake --build _build # building
```
Output will be:
```bash
_build
# ... CMake files ...
├── without_sanitizers
│   ├── alloc-dealloc-mismatch_clean
│   ├── alloc-size-too-big_clean
│   ├── calloc-overflow_clean
│   ├── container_clean
│   ├── dl_clean
│   ├── double-free_clean
│   ├── global-buffer-overflow_clean
│   ├── heap-buffer-overflow_clean
│   ├── heap-use-after-free_clean
│   ├── signed_overflow_clean
│   ├── simple_clean
│   ├── stack-buffer-overflow_clean
│   └── uninit_mem_clean
└── with_sanitizers
    ├── alloc-dealloc-mismatch_san
    ├── alloc-size-too-big_san
    ├── calloc-overflow_san
    ├── container_san
    ├── dl_san
    ├── double-free_san
    ├── global-buffer-overflow_san
    ├── heap-buffer-overflow_san
    ├── heap-use-after-free_san
    ├── signed_overflow_san
    ├── simple_san
    ├── stack-buffer-overflow_san
    └── uninit_mem_san
```

## How to: run

simply:
```bash
./_build/with_sanitiser/${filename}_san # with sanitizer
./_build/without_sanitiser/${filename}_clean # without sanitizer
```

for additional options:
just run the compiled executable with ASAN_OPTIONS=help=1. Same for other sanitizers. Easiest way.

## How to: build with Clang
```bash
cd ${path-to-src}
rm -rf _build # clear build directory beforehand
CC=clang CXX=clang++ cmake -S . -B _build # _build here is folder to build
cmake --build _build # building
```

## Additional resources:
* [MSVC](https://learn.microsoft.com/en-us/cpp/sanitizers/asan?view=msvc-170)
* [g++ Instrumentation Options](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html)
