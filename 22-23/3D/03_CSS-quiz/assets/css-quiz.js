introJs().start();

document.addEventListener('DOMContentLoaded', () => {
    Prism.highlightAll();
});

var nRulesToGuess = 0;
const rulesToGuess = parseCSS(document.querySelector('#rules-to-guess').textContent);
var appliedRules = [];

printStatistics();

var wrongRules = [];
var correctRules = [];
var semiCorrectRules = [];

function parseCSS(cssText) {
    cssText = cssText.trim();
    var cssRules = cssText.split(';');
    var cssObject = {};

    for (var i = 0; i < cssRules.length; i++) {
        var cssRule = cssRules[i].trim();
        if (cssRule) {
            var parts = cssRule.split(':');
            var key = parts[0].trim();
            var value = parts[1].trim();
            cssObject[key] = value;

            nRulesToGuess++;
        }
    }

    return cssObject;
}

function checkRuleCorrectness(property, value) {

    var textRule = property + ': ' + value + ';\n'

    for (const key in rulesToGuess) {
        if (property == key) {
            if (value == rulesToGuess[key]) {
                correctRules.push(textRule);
            } else {
                semiCorrectRules.push(textRule);
            }

            return;
        }
    }

    wrongRules.push(textRule);
}

function printRulesStatus() {
    var correctRulesCnt = document.querySelector('#correct-rules');
    var semiCorrectRulesCnt = document.querySelector('#semi-correct-rules');
    var wrongRulesCnt = document.querySelector('#wrong-rules');

    correctRulesCnt.textContent = '';
    var text = '';
    for (const rule of correctRules) {
        text += rule;
    }
    correctRulesCnt.textContent = text;	

    semiCorrectRulesCnt.textContent = '';
    text = '';
    for (const rule of semiCorrectRules) {
        text += rule;
    }
    semiCorrectRulesCnt.textContent = text;

    wrongRulesCnt.textContent = '';
    text = '';
    for (const rule of wrongRules) {
        text += rule;
    }
    wrongRulesCnt.textContent = text;	
}

function printStatistics() {
    var nCorrectRules = correctRules == undefined ? 0 : correctRules.length;
    var nSemiCorrectRules = semiCorrectRules == undefined ? 0 : semiCorrectRules.length;
    var nWrongRules = wrongRules == undefined ? 0 : wrongRules.length;

    const correctPercent = (nCorrectRules / nRulesToGuess) * 100;
    const semiCorrectPercent = (nSemiCorrectRules / nRulesToGuess) * 100;
    const wrongPercent = (nWrongRules / nRulesToGuess) * 100;

    document.querySelector('#correct-stats').textContent =
        correctPercent.toFixed(2) + '%' + ' (' + nCorrectRules + '/' + nRulesToGuess + ')'
}

document.querySelector('#editing').addEventListener('keyup', () => {

    wrongRules = [];
    correctRules = [];
    semiCorrectRules = [];

    const userRules = document.querySelector('#editing').value.trim();
    const userRulesArray = userRules.split(';');
    const userDefinedElm = document.querySelector('#user-defined-elm');

    // Removes all the previous applied CSS rules.
    for (var rule of appliedRules) {
        userDefinedElm.style.removeProperty(rule);
    }

    for (let i = 0; i < userRulesArray.length; i++) {
        const userRule = userRulesArray[i].trim();
        const ruleArray = userRule.split(':');

        if (ruleArray.length == 2) {
            // The rule is correctly composed by a key-value pair.
            const userProperty = ruleArray[0].trim();
            const userValue = ruleArray[1].trim();

            appliedRules.push(userProperty);
            checkRuleCorrectness(userProperty, userValue);

            const style = {};
            style[userProperty] = userValue;
            Object.assign(userDefinedElm.style, style);					
        }

        printRulesStatus();
        printStatistics();
    }
});
