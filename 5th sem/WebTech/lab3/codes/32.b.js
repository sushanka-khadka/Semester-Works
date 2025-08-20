const fs = require('fs');

// ---------- Read from JSON file ----------
const jsonData = fs.readFileSync('32.b.json', 'utf-8');
const data = JSON.parse(jsonData);

console.log("Original Data:", data);

// ---------- Modify or Add Data ----------
data.grade = 'A+';
data.subjects = ['DAA', 'WEB', 'AI'];

// ---------- Write to JSON file ----------
fs.writeFileSync('32.b.json', JSON.stringify(data, null, 2));

console.log("Data updated and written to 32.b.json!");
