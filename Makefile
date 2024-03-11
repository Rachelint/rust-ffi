TARGET = target
DEBUG = $(TARGET)/debug

SO_SUFFIX = so
ifeq ($(shell uname -s), Darwin)
	SO_SUFFIX = dylib
endif

.PHONY: c-call-rust-by-cbindgen
c-call-rust:
	cargo build -p c-call-rust-by-cbindgen
	gcc -o $(TARGET)/c-call-rust-by-cbindgen c-call-rust/main.c -lc_call_rust_by_cbindgen -Ltarget/debug
	$(TARGET)/c-call-rust-by-cbindgen

.PHONY: rust-call-c
rust-call-c:
	gcc --shared -fPIC rust-call-c/awesome.c -o rust-call-c/libawesome.$(SO_SUFFIX)
	LD_LIBRARY_PATH=rust-call-c cargo run -p rust-call-c

.PHONY: miri-check
miri-check:
	cd miri-check && cargo +nightly miri run
