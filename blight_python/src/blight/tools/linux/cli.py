import typer
import blight_cxx.linux as linux

from pathlib import Path

app = typer.Typer()

@app.command()
def inject_so(pid: int, dll_path: Path):
    linux.inject_so(pid, str(dll_path.resolve()))