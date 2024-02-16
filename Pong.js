var DIRECTION = {
    IDLE: 0,
    up: 1,
    DOWN:2,
    LEFT: 3,
    RIGHT:4
};

var rounds = [5, 5, 3, 3, 2];
var colors = ['#1abc9c',  '#2ecc71', '#3498db', '#8c52ff', '#9b59b6'];

var Ball = {
    new: function (increamentedSpeed){
        return {
            width: 10,
            height: 10,
            x: (this.canvas.width / 2) - 9,
            y: (this.canvas.height/ 2) - 9,
            moveX: DIRECTION.IDLE,
            moveY: DIRECTION.IDLE,
            speed: increamentedSpeed || 7
        };
    }
};

var Plyer = {
    new: function (side) {
        return {
            width: 10,
            height: 10,
            x: side === 'left' ? 150 : this.canvas.width - 150,
            y: (this.canvas.height / 2) - 35,
            score: 0,
            move: DIRECTION.IDLE,
            speed: 0
        };
    }
};

