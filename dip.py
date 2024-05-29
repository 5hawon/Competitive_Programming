


#Concatenation of original and flipped images horizontally
h_concat = cv2.hconcat([img,horizontal,vertical,both])
print(h_concat.shape)
plt.imshow(cv2.cvtColor(h_concat, cv2.COLOR_BGR2RGB)) # converting BGR to RGB for using matplotlib
plt.axis('off')
plt.show()