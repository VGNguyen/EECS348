
document.getElementById("form").addEventListener("submit", (e) => {
    e.preventDefault();

    var pass1 = document.getElementById("pwd");
    var pass2 = document.getElementById("pwdV");
    if (pass1.value.length<8){
    alert("The password needs to be at least 8 characters long");
    }else if(pass1.value!=pass2.value){
        alert("These passwords do not match");
    }else{
        alert("The passwords match!");
    }

});