# digital-signal-processing
Core DSP Concepts in Time Series Analysis

Applying DSP concepts to time series analysis is a powerful approach that provides a different and often more insightful "lens" than traditional statistical methods. At its core, it's about treating a time series not just as a sequence of numbers, but as a **signal**.

The single most important shift in perspective that DSP provides is moving from the **Time Domain** to the **Frequency Domain**.

*   **Time Domain Analysis:** Asks "What was the value at a specific point in time?" (e.g., What was the stock price at 10:30 AM?).
*   **Frequency Domain Analysis:** Asks "What cycles or periodic patterns exist over the entire duration of the signal?" (e.g., Is there a recurring pattern in the stock price every 24 hours or every 7 days?).

Here are the core DSP concepts used in time series analysis, from the most fundamental to the more advanced.

---

### 1. Filtering (Signal Smoothing and Decomposition)

This is the most direct and common application of DSP. The goal is to separate the signal into different components, typically the underlying trend and the high-frequency noise.

*   **DSP Concept:** **Low-Pass Filtering**. A low-pass filter allows low-frequency signals (the slow-moving trend) to pass through while blocking high-frequency signals (the jagged, short-term noise).
*   **Time Series Equivalent:**
    *   **Moving Average:** A simple moving average is a basic DSP **Finite Impulse Response (FIR) filter**. It smooths the data by averaging recent points, effectively "smearing out" the noise.
    *   **Exponential Smoothing:** This is a classic time-series method that gives more weight to recent data points. In DSP terms, it's a simple **Infinite Impulse Response (IIR) filter**.
*   **Primary Goal:** **Noise Reduction and Trend Extraction.** By filtering out the noise, you get a clearer view of the underlying trend and seasonality, which is often the first step in any forecasting model.

---

### 2. Frequency & Power Spectrum Analysis (The Fourier Transform)

This is the heart of DSP and its most transformative contribution to time series analysis. It allows you to see your data in a completely new way.

*   **DSP Concept:** **The Fast Fourier Transform (FFT)**. The FFT is an efficient algorithm that takes a time-domain signal (your time series) and decomposes it into the various sine waves (frequencies) that make it up. Think of it like a prism splitting white light into its constituent colors.
*   **Time Series Equivalent:** **Spectral Analysis** or **Periodogram Analysis**.
*   **Primary Goal:** **Identifying Seasonality and Cyclicality.**
    *   If you have daily sales data for a year and run an FFT on it, you will likely see a huge spike at a frequency corresponding to a 7-day cycle (weekly seasonality).
    *   If you analyze temperature data, you'll see spikes at 24-hour (daily cycle) and 365-day (yearly cycle) frequencies.
    *   This is far more robust than just "eyeballing" a chart. The FFT gives you a precise, mathematical measurement of the strength of different cycles in your data.

---

### 3. Correlation (Finding Self-Similarity)

This concept helps you understand how a time series relates to itself at different points in time.

*   **DSP Concept:** **Autocorrelation**. This is a specific type of correlation where a signal is compared against a time-shifted version of itself.
*   **Time Series Equivalent:** **Autocorrelation Function (ACF) Plot**. The ACF plot is a standard tool in time series analysis (e.g., for ARIMA models).
*   **Primary Goal:** **Confirming Seasonality and Finding Lags.**
    *   The autocorrelation plot shows you the correlation between the series `y(t)` and `y(t-k)` for different lag values `k`.
    *   If you have a strong weekly seasonality in your data, the ACF plot will show a significant spike at a lag of 7, 14, 21, etc. This confirms the result you might find from an FFT, but from a time-domain perspective. It's crucial for determining the parameters of models like ARIMA.

---

### 4. Resampling (Changing Time Granularity)

Often, your data isn't at the right frequency for the analysis you want to perform.

*   **DSP Concept:** **Downsampling (Decimation)** and **Upsampling (Interpolation)**.
*   **Time Series Equivalent:** **Aggregation** and **Imputation/Interpolation**.
*   **Primary Goal:** **Data Preparation and Alignment.**
    *   **Downsampling/Aggregation:** Converting high-frequency data to a lower frequency. For example, taking tick-by-tick stock data and creating 1-minute bars, or taking daily sales data and creating weekly or monthly totals. This reduces noise and makes long-term trends easier to see.
    *   **Upsampling/Interpolation:** Creating data points where none existed. This is essential when you need to align two time series with different frequencies (e.g., you have monthly marketing spend but weekly sales data) or to fill in missing values in a series.

### Summary Table

| Time Series Term/Goal | Core DSP Concept | What It Does |
| :--- | :--- | :--- |
| **Smoothing / De-noising** | **Low-Pass Filtering** | Removes random, high-frequency fluctuations to reveal the underlying trend. |
| **Finding Seasonality/Cycles** | **Fourier Transform (FFT)** | Decomposes the time series into its constituent frequencies, showing the strength of each cycle. |
| **Analyzing Self-Similarity** | **Autocorrelation** | Measures how much the current value is related to past values at different time lags. |
| **Changing Time Granularity** | **Resampling** | Aggregating data to a lower frequency (downsampling) or filling in gaps (upsampling). |

By applying these core DSP concepts, you can gain a much deeper and more robust understanding of the underlying processes that generate your time series data.
