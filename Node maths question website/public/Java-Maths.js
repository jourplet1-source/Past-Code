async function GetQuestion(Qnum) {
    let Data={
        number:Qnum//puts the input into a form where it can be combined with Json data to alter what is called
    }
    const response=await fetch("/get-data", {
        method:"POST",
        body:JSON.stringify(Data),
        headers:{
            "Content-Type":"application/json"
        }
    });
    const data = await response.json();
    console.log(data);
    ans=data.Item.Answer.N;//Writing the stored answer into a variable lets it be tested against later
    console.log(ans)
    document.getElementById("Q-Descriptor").innerHTML=data.Item.Question.S;//This is written directly into the HTML without storing anything in a variable since the question doesn't actually matter to the program.
}
count=1
GetQuestion(count);
function Check(){
    x=document.getElementById('Q-ans').value
    console.log("Hello")
    if (x==ans){
        if (count<5){
            document.getElementById("Q-Correct").innerHTML="Correct"
            count+=1;//Since it is only inside the correct function that count can increase, the question won't move on until a user solves it.
            document.getElementById("Q-Number").innerHTML="Question "+count
            GetQuestion(count);
        }
        else{
            document.getElementById("Q-area").innerHTML="Correct<br>You have answered all questions correctly"//This functionally ends the program
        }
    }
    else{
        document.getElementById("Q-Correct").innerHTML="Incorrect"
        
    }
    document.getElementById("entry").innerHTML="<label for=\"Q-ans\">Answer:</label> <input type=\"text\" name=\"Q-ans\" id=\"Q-ans\"><br><br>"//Reloading the HTML input field was the simplest way I could find to clear the user imput after clicking the submit button
    Store=document.getElementById("Q-ans")
    Store.addEventListener("keydown", function(event){//If I dn't redefine the event listener after reloading the text box, it stops functioning so I had to copy the code for the event listener into the function that runs after loading the content.
        if (event.key === 'Enter'){
            Check();
        }
    })
}
Store=document.getElementById("Q-ans")//I had to set a variable equal to Q-ans since the hyphen broke the event listener due to making it try to subtract ans from Q
document.getElementById("Submit").onclick = Check;//https://www.freecodecamp.org/news/form-validation-with-html5-and-javascript/ - user validation research
Store.addEventListener("keydown", function(event){
    if (event.key === 'Enter'){
        Check();
    }
})
