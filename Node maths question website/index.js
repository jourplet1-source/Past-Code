const express = require("express"); //run cmd to make node work, then 'npm install' in terminal to calll dependant node functions, when calling new functions run 'npm install FunctionName --save'
const { DynamoDBClient, ListBackupsCommand, UpdateItemCommand, PutItemCommand, GetItemCommand } = require("@aws-sdk/client-dynamodb");

// Many of the AWS commands used in this file and in QUpdate.js were sourced from https://docs.aws.amazon.com/AWSJavaScriptSDK/v3/latest/Package/-aws-sdk-client-dynamodb/

const app = express();
app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.listen(3000, () => console.log("Listening on http://localhost:3000"));

const awsConfig = require("./config.json");//config.json is the file that provides the AWS keys that I use to access the database, it contains two variables in an array- One storing the region, and the other being another array that stores both access keys.
const dynamoDBClient = new DynamoDBClient(awsConfig);

app.use(express.static("./public"));

const client = new DynamoDBClient({ "region": "eu-west-2" });


async function getData(request, response){
  Q="Q" + request.body.number;//By passing an integer in and concatonating it to a Q, I'm able to manually create the primary keys for the AWS database
  console.log(Q);
  const input = {
    "Key": {
      "QID": {
        "S": Q
      }
    },
    "TableName": "Question_Store"
  };
  const command = new GetItemCommand(input);
  const receive =await dynamoDBClient.send(command);//Allows the program to retrieve the data from AWS before trying to use it by writing it to another variable with an Await command
  console.log(receive);
  response.send(
    receive
  )
}

app.post("/get-data", getData);//app.post has to be used in order to pass a variable into getData from Java-Maths

