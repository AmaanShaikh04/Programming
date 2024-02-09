// Calculator.js
import React, { useState } from 'react';

function Calculator() {
  const [input, setInput] = useState('');
  const [result, setResult] = useState(0);

  const handleButtonClick = (value) => {
    setInput((prevInput) => prevInput + value);
  };

  const handleCalculate = () => {
    try {
      setResult(eval(input));
    } catch (error) {
      setResult('Error');
    }
  };

  return (
    <div>
      <input type="text" value={input} readOnly />
      <br />
      <button onClick={() => handleButtonClick('1')}>1</button>
      {/* Include buttons for other digits and mathematical operations */}
      <br />
      <button onClick={handleCalculate}>=</button>
      <br />
      <div>Result: {result}</div>
    </div>
  );
}

export default Calculator;
