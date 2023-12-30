pandoc "./report.md" "./metadata.yaml" \
    --output="./report.pdf" \
    --from markdown \
    --template="./eisvogel.tex" \
    --number-sections \
    --resource-path="./" \
    --listings \
    --pdf-engine=xelatex
