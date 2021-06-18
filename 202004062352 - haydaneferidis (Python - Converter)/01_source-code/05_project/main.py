#!/usr/bin/python
import sys
import csv
import json
from xml.etree import ElementTree as ET


inputFile = sys.argv[1]
outputFile = sys.argv[2]
convertType = sys.argv[3]


def csv2xml(csvFile,xmlFile):
	csvData = csv.reader(open(csvFile),delimiter=';')
	xmlData = open(xmlFile,'w')
	xmlData.write('<?xml version="1.0"?>'+"\n")
	xmlData.write('<root>'+"\n")

	rowNum = 0
	for row in csvData:
	    if rowNum == 0:
	        tags = row
	        for i in range(len(tags)):
	            tags[i] = tags[i].replace(' ', '_')
	    else: 
	        xmlData.write('<row>' + "\n")
	        for i in range(len(tags)):
	            xmlData.write('    ' + '<' + tags[i] + '>' \
	                          + row[i] + '</' + tags[i] + '>' + "\n")
	        xmlData.write('</row>' + "\n")
	            
	    rowNum +=1

	xmlData.write('</root>' + "\n")
	xmlData.close()

def xml2csv(xmlFile,csvFile):
	sep = ';'
	endl = "\n"
	content = ""
	text = ""
	depth = 0

	rows = []
	header = []
	row = []

	with open(xmlFile, 'r') as fp:
	    buffer0 = fp.read(10)
	    while buffer0:
	        content += buffer0
	        try:
	            if '<?' in content:
	                index1 = content.index('<', content.index('<?') + 1) + 1
	            else:
	                index1 = content.index('<') + 1
	            index2 = content.index('>', index1)
	            if ' ' in content[index1:]:
	                index2 = min(index2, content.index(' ', index1))
	            endTag = content[index1] == '/' if index1 < len(content) - 1 else False
	            if endTag:
	                index1 += 1

	        except ValueError:
	            index1 = False
	            index2 = False
	        
	        if index1 and index2 and index1 < len(content) - 1:
	            if not endTag:
	                tagname = content[index1:index2]
	                depth += 1
	                content = content[index2:]
	                if depth == 3 and tagname not in header:
	                    header.append(tagname)

	            else:
	                tagname = content[index1:index2]
	                text = content[:index1].strip("</>")
	                content = content[index2+1:]
	                depth -= 1
	                if depth == 1:
	                    rows.append(row)
	                    row = []
	                elif depth == 2:
	                    row.insert(header.index(tagname), text)

	        buffer0 = fp.read(10)

	with open(csvFile, 'w') as fp:
		fp.write(sep.join(header))
		fp.write(endl)
		fp.write(endl.join(map(lambda row: sep.join(row), rows)))

def xml2json(xmlFile,jsonFile):
	pass
def json2xml(jsonFile,xmlFile):
  	pass
def csv2json(csvFile,jsonFile):
	csv_rows = []

	with open(csvFile) as csvfile:
		reader = csv.DictReader(csvfile,delimiter=';')
		field = reader.fieldnames
		for row in reader:
			csv_rows.extend([{field[i]:row[field[i]] for i in range(len(field))}])
		with open(jsonFile, "w") as f:
			f.write(json.dumps(csv_rows, sort_keys=False, indent=4, separators=(',', ': ')))
			f.write(json.dumps(csv_rows))

def json2csv(jsonFile,csvFile):
	pass

if convertType == "1":
	csv2xml(inputFile, outputFile)
elif convertType == "2":
	xml2csv(inputFile, outputFile)
elif convertType == "3":
	xml2json(inputFile, outputFile)
elif convertType == "4":
	json2xml(inputFile, outputFile)
elif convertType == "5":
	csv2json(inputFile, outputFile)
elif convertType == "6":
	json2csv(inputFile, outputFile)