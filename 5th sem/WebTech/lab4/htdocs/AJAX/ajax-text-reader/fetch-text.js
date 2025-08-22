// valila Javascript code to fetch text from a URL and display it in a div

function loadTextFile() {
    const xhr = new XMLHttpRequest();
    xhr.open("GET", "file.txt", true);

    xhr.onload = function() {
        if (this.status === 200) {
            document.getElementById("output").innerText = this.responseText;
        }else
            document.getElementById("output").innerText = "Failed to load file: " + this.status;    
    };

    xhr.onerror = function() {
        document.getElementById("output").innerText = "Request Error.";
    };

    xhr.send();
}

