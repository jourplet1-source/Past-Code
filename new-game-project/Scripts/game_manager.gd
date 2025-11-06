extends Node

@onready var coin_count: Label = %CoinCount

var score = 0

func add_score():
	score+=1
	coin_count.text= "Coins: " + str(score)
