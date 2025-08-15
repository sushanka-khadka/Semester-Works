from pdf2docx import Converter

# path to the PDF file and output DOCX file
pdf_file = "dip_lab.pdf"
docx_file = "dip_lab.docx"

# convert PDF to DOCX
cv= Converter(pdf_file)
cv.convert(docx_file, start=0, end=None)    # convert all pages
cv.close()

print(f"Converted '{pdf_file}' to '{docx_file}'")

