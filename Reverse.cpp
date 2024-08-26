#include<iostream>
#include<string>
using namespace std;

int reverse(int x)
{
    int rev = 0;
    int digit ;
    while(x != 0)
    {
        digit =  x%10;
        rev = (rev*10) + digit;
        x = x / 10;
    }
    return rev;

}

main()
{
    cout<<INT32_MAX;
    return 0;
}



const fs = require('fs');
function createFileFolderStructure(jsonData, parentPath = '') {
for (const item of jsonData) {
const { type, name, children } = item;
const itemPath = `${parentPath}/${name}`;
if (type === 'file') {
fs.writeFileSync(itemPath, '');
console.log(`Created file: ${itemPath}`);
} else if (type === 'folder') {
fs.mkdirSync(itemPath);
console.log(`Created folder: ${itemPath}`);
if (children && children.length > 0) {
createFileFolderStructure(children, itemPath);
}
}
}
}
// Usage example
const jsonFilePath = 'task8.json';
fs.readFile(jsonFilePath, 'utf8', (err, data) => {
if (err) {
console.error(`Error reading JSON file: ${err}`);
return;