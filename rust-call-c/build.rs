use std::env;
use std::path::PathBuf;

fn main() {
    let target = env::var("CARGO_MANIFEST_DIR").unwrap();
    // Tell cargo where to find libs.
    println!("cargo:rustc-link-search={}", target);
    // Tell cargo to link the awesome lib.
    println!("cargo:rustc-link-lib=awesome");

    let bindings = bindgen::Builder::default()
        .header("awesome.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    // Write the bindings to the $OUT_DIR/bindings.rs file.
    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
