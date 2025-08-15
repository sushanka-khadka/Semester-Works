import os
from pypdf import PdfWriter


pdf_files = [file for file in os.listdir('./to pdfs') if file.lower().endswith('.pdf')]


# intialize PdfWriter
merger= PdfWriter()

# append each pdf file to the merger
for pdf in pdf_files:
    print("Appending:", pdf)
    merger.append("to pdfs/" + pdf)


output_file = "dip_lab.pdf"
merger.write(output_file)
merger.close()

print(f"Merged {len(pdf_files)} PDF files into '{output_file}'")
print("Done!")