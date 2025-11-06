const express = require("express"); //run cmd to make node work, then 'npm install' in terminal to calll dependant node functions, when calling new functions run 'npm install FunctionName --save'
const { DynamoDBClient, ListBackupsCommand, UpdateItemCommand, BatchWriteItemCommand, GetItemCommand } = require("@aws-sdk/client-dynamodb");

const app=express();//The same syntax is used as in the index file, but with no connection to a front end
app.use(express.urlencoded({extended: false}));
app.use(express.static("./public"));


const awsConfig = require("./config.json");
const dynamoDBClient = new DynamoDBClient(awsConfig); 

const commandParameters = {
    "RequestItems":{
        "Question_Store":[
            {
                "PutRequest":{
                    Item: {
                        "QID": { S: "Q1" },
                        "Question": { S: "What is the cubed root of 512" },//The code needs to be directly modified to change the questions in the database
                        "Answer": { N: "8" }
                    }
                }
            },
            {
                "PutRequest":{
                    Item: {
                        "QID": { S: "Q2" },
                        "Question": { S: "What is the sum of the squares of the first 6 natural numbers?" },
                        "Answer": { N: "140" }
                    }
                }
            },
            {
                "PutRequest":{
                    Item: {
                        "QID": { S: "Q3" },
                        "Question": { S: "What is the 10th value in the fibbonachi sequence" },
                        "Answer": { N: "55" }
                    }
                }
            },
            {
                "PutRequest":{
                    Item: {
                        "QID": { S: "Q4" },
                        "Question": { S: "What is the numerator of the most simplified version of the result of 1/3+1/4+1/5" },
                        "Answer": { N: "47" }
                    }
                }
            },
            {
                "PutRequest":{
                    Item: {
                        "QID": { S: "Q5" },
                        "Question": { S: "What is the total area under the line y=2x+3 between x=1 and x=4" },
                        "Answer": { N: "39" }
                    }
                }
            }
        ]
    }
}

async function Load() {
    try {
      const command = new BatchWriteItemCommand(commandParameters);
      const data = await dynamoDBClient.send(command);
      console.log("Command success:", data);
    } catch (err) {
      console.error("Command error:", err);
    }
}
Load();//To update the questions in the external file, alter the questions and answers in this javascript and then run node QUpdate.js in the cmd terminal