use log::LevelFilter;
use log::{debug, error, info, trace, warn};
use pretty_env_logger::formatted_builder;
use std::ffi::CStr;
use std::ffi::{c_char, CString};

#[unsafe(no_mangle)]
pub extern "C" fn rust_init_logger() {
    formatted_builder()
        .filter_level(LevelFilter::Info)
        .parse_default_env()
        .default_format()
        .format_module_path(false)
        .format_timestamp(None)
        .format_target(false)
        // .format(|buf, record| {
        //     writeln!(
        //         buf,
        //         "{:<5} [{}] > {}",
        //         record.level(),
        //         "my_app", // 替换为你想要的名称
        //         record.args()
        //     )
        // })
        .init();

    debug!("Logger initialized");
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_log_trace(data: *const c_char) {
    let sz = unsafe { CStr::from_ptr(data) };
    trace!("{}", &sz.to_str().unwrap());
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_log_debug(data: *const c_char) {
    let sz = unsafe { CStr::from_ptr(data) };
    debug!("{}", &sz.to_str().unwrap());
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_log_info(data: *const c_char) {
    let sz = unsafe { CStr::from_ptr(data) };
    info!("{}", &sz.to_str().unwrap());
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_log_warn(data: *const c_char) {
    let sz = unsafe { CStr::from_ptr(data) };
    warn!("{}", &sz.to_str().unwrap());
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_log_error(data: *const c_char) {
    let sz = unsafe { CStr::from_ptr(data) };
    error!("{}", &sz.to_str().unwrap());
}

#[unsafe(no_mangle)]
pub extern "C" fn rust_panic(data: *const c_char) -> ! {
    let sz = unsafe { CStr::from_ptr(data) };
    panic!("{}", &sz.to_str().unwrap());
}
