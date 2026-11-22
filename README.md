# Dora

Dora is a command-line file search utility written in C, designed for Linux environments. Its purpose is to provide a simple and practical way to locate files and directories directly from the terminal, offering an alternative to navigating through the filesystem manually.

## Build

To compile Dora, run the following command from the project root directory:

```bash
make
```

After a successful build, the executable will be generated at:

```text
bin/dora
```

## Install

To install Dora on your system, run:

```bash
sudo make install
```

By default, the executable is installed in `/usr/local/bin`, making it available system-wide.

After installation, you can run Dora from any directory:

```bash
dora -h
```

## Usage

### Syntax

```bash
dora [OPTIONS] -d <directory> -n <name>
```

When running Dora directly from the build directory, use:

```bash
./bin/dora [OPTIONS] -d <directory> -n <name>
```

### Options

| Option | Description |
|---|---|
| `-h`, `--help` | Display the help message. |
| `-d`, `--directory <directory>` | Specify the directory where the search will start. |
| `-n`, `--name <name>` | Search for a file or directory by name. |
| `-i`, `--ignore-case` | Ignore case distinctions when matching names (e.g., `DORA.txt` and `dora.txt` are treated as equivalent). |
| `-t`, `--type <file_type>` | Filter results by entry type: `f` for files or `d` for directories. |
| `-e`, `--extension <extension>` | Filter files by extension (e.g., `pdf`, `txt`). |

## Examples

Search for a specific file in the Downloads directory:

```bash
dora -d Downloads -n document.pdf
```

Search for files with a specific extension:

```bash
dora -d Downloads -e pdf
```

Search for a directory, ignoring case distinctions:

```bash
dora -d Documents -n projects -i -t d
```

## Uninstall

To remove Dora from your system, run:

```bash
sudo make uninstall
```

This removes the Dora executable from the installation directory.
