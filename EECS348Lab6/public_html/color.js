
var input = document.getElementById("input");
var input2 = document.getElementById("input2");
var p1 = document.getElementById("p1")

input.addEventListener("keydown", function(event) {
    if (event.key === "Enter") {
        p1.style.color = input.value;
        p1.style.borderWidth =input2.value+"px";
    }
});