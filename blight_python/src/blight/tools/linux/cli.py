import typer
import blight_cxx.linux as linux

from pathlib import Path

app = typer.Typer()

@app.command()
def so_inject(pid: int, dll_path: Path):
    linux.so_inject(pid, str(dll_path.resolve()))