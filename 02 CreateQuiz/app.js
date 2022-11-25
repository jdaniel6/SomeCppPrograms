//taken from https://dev.to/varshithvhegde/create-your-own-live-web-editor-using-html-css-and-javascript-3j73
var j=0;
//Function for live Rendering
function update(i) {
    if(i==0){
    let htmlCode=document.getElementById("htmlCode").value;
    let cssCode=document.getElementById("cssCode").value;
    let javascriptCode=document.getElementById("javascriptCode").value;
    const htmlArray = htmlCode.split(" ");
    for(let i = 0; i < htmlArray.length; i++){
        if(htmlArray[i] == 'createmcq')
            htmlArray[i] = 'Cat is a type of \n<ol><li>Animal</li><li>Food</li><li>Plant</li></ol>\n';
    }
    htmlCode = "";
    for(let i = 0; i < htmlArray.length; i++){
        htmlCode += htmlArray[i] + " ";
    }
    let text=htmlCode+"<style>"+cssCode+"</style>"+"<scri"+"pt>"+javascriptCode+"</scri"+"pt>";
    let iframe=document.getElementById('viewer').contentWindow.document;
    iframe.open();
    iframe.write(text);
    iframe.close();
    }

    else if(i==1){

        let htmlCode=document.getElementById("htmlCode").value;
        let html=htmlCode.slice(0,htmlCode.length);
        document.getElementById("htmlCode").value=html;
        j=1;

    }
}
