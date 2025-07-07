import numpy as np
import matplotlib.pyplot as plt
import  cpp_ma_filter

def main():
    signal_length=200
    time = np.linespace(0,1,signal_length);
    clean_signal = np.sin(time * np.pi*2*5)+ np.sin(time*np.pi*2*10) *0.5;
    noise = np.random.normal(0,0.5,signal_length);
    original_signal = clean_signal + noise
    window_size =10
    print(f"Creating process_vector method")

    smoothed_signal = cpp_ma_filter.process_vector(original_signal)
    print("Plotting the data::")
    plt.figure(figsize=(14,7))
    plt.plot(original_signal,label="original signal",color='gray',alpha=0.8)
    plt.plot(smoothed_signal,label=f'smoothed Signal',color='purple',linewidth=2.5)
    plt.title('Calling C++')
    
#g++ -O3 -Wall -shared -std=c++17 -fPIC $(python3-config --cflags) -I./pybind11/include ma_filter_bindings.cpp -o cpp_ma_filter$(python3-config --extension-suffix)
