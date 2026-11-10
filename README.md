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

### Clean

To remove generated build files and the executable:

```bash
make clean
```

## Usage

### Syntax

```bash
./bin/dora [OPTIONS] -d <directory> -n <name>
```

### Description

Search for files and directories on your local machine.

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
./bin/dora -d Downloads -n document.pdf
```
