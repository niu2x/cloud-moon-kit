import typer
import blight_cxx
import platform

app = typer.Typer()

if platform.system() == 'Windows':
	from blight.tools.windows import cli as windows_cli
	app.add_typer(windows_cli.app, name="windows")

if platform.system() == 'Linux':
	from blight.tools.linux import cli as linux_cli
	app.add_typer(linux_cli.app, name="linux")
