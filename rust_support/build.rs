use std::env;
use std::fs;

fn main() {
    let header_path = "include/yy/rust_support.h";

    let _ = fs::remove_file(header_path);

    let crate_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    cbindgen::Builder::new()
        .with_crate(crate_dir)
        .with_config(cbindgen::Config::from_file("cbindgen.toml").unwrap())
        .generate()
        .expect("Unable to generate bindings")
        .write_to_file(header_path);
}
