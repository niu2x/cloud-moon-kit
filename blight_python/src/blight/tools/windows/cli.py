import typer
import sys
from pathlib import Path
import blight_cxx.windows as windows

app = typer.Typer()

@app.command()
def dll_inject(pid: int, dll_path: Path):
    windows.request_debug_privilege(sys.argv)
    windows.dll_inject(pid, str(dll_path.resolve()))
