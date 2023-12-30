# Lab 02 - Introduction To Data Science/ CSC14119 Report

This report is powered by Eisvogel - A clean pandoc LaTeX template to convert your markdown files to PDF or LaTeX. It is designed for lecture notes and exercises with a focus on computer science. The template is compatible with pandoc 3.

Installation
1. Install pandoc from [http://pandoc.org/](http://pandoc.org/). You also need to install [LaTeX](https://en.wikibooks.org/wiki/LaTeX/Installation#Distributions).
2. Build pdf by using the command

```bash
chmod 777 build.sh
./build.sh
```

or

```bash
pandoc "./report.md" "./metadata.yaml" \
    --output="./report.pdf" \
    --from markdown \
    --template="./eisvogel.tex" \
    --number-sections \
    --resource-path="./" \
    --listings \
    --pdf-engine=xelatex
```